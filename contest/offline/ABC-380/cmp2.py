import random
import subprocess

# 生成随机测试用例
def generate_test_case():
    MAX_N = 10 # 5 * 10**5
    MAX_Q = 5 # 2 * 10**5

    # 随机生成 N 和 Q
    n = random.randint(1, MAX_N)
    q = random.randint(1, MAX_Q)
    
    queries = []
    has_query_type_2 = False
    
    for _ in range(q):
        if random.random() < 0.5:  # 随机选择操作类型
            # 第一类操作
            x = random.randint(1, n)
            c = random.randint(1, n)
            queries.append(f"1 {x} {c}")
        else:
            # 第二类操作
            c = random.randint(1, n)
            queries.append(f"2 {c}")
            has_query_type_2 = True
    
    # 确保至少有一个第二类操作
    if not has_query_type_2:
        c = random.randint(1, n)
        queries[random.randint(0, q-1)] = f"2 {c}"
    
    return n, q, queries

# 写入测试用例到文件
def write_test_case_to_file(filename, n, q, queries):
    with open(filename, "w") as f:
        f.write(f"{n} {q}\n")
        f.write("\n".join(queries) + "\n")

# 读取程序输出
def read_output(filename):
    with open(filename, "r") as f:
        return f.read().strip()

# 对拍测试
def run_test():
    for i in range(114514):  # 对拍次数
        print(f"Running test {i + 1}...")
        n, q, queries = generate_test_case()
        write_test_case_to_file("input.txt", n, q, queries)
        
        # 运行两个程序
        subprocess.run(["./a.out"], stdin=open("input.txt", "r"), stdout=open("a_output.txt", "w"))
        subprocess.run(["./b.out"], stdin=open("input.txt", "r"), stdout=open("b_output.txt", "w"))
        
        # 比较输出
        a_output = read_output("a_output.txt")
        b_output = read_output("b_output.txt")
        
        if a_output != b_output:
            print("Mismatch found!")
            print("Input:")
            print(f"{n} {q}")
            print("\n".join(queries))
            print("\nYour Output:")
            print(a_output)
            print("\nExpected Output:")
            print(b_output)
            return  # 退出，方便调试
            
    print("All tests passed!")

if __name__ == "__main__":
    run_test()

