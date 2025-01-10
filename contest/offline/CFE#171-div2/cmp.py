import random
import subprocess

def generate_test_case(n):
    """生成一个测试用例，保证递增且符合题目输入要求"""
    a = [random.randint(1, 10)]
    for _ in range(1, n):
        a.append(a[-1] + random.randint(1, 10))
    return a

def run_program(program_path, input_data):
    """运行程序并返回其输出"""
    process = subprocess.run(
        program_path,
        input=input_data,
        text=True,
        capture_output=True
    )
    return process.stdout.strip()

def main():
    t = 1  # 固定为 1，方便多次生成
    for _ in range(10**19):  # 生成多组测试
        n = random.randint(2, 10)  # 修改 n 范围
        a = generate_test_case(n)
        
        # 构造输入
        input_data = f"{t}\n{n}\n" + " ".join(map(str, a)) + "\n"
        
        # 运行两个程序
        a_out = run_program("./a.out", input_data)
        b_out = run_program("./b.out", input_data)
        
        # 比较输出
        if a_out != b_out:
            print("Mismatch found!")
            print("Input:")
            print(input_data)
            print("a.out output:")
            print(a_out)
            print("b.out output:")
            print(b_out)
            break
    else:
        print("All test cases passed.")

if __name__ == "__main__":
    main()

