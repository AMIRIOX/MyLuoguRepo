import random
import string
import subprocess

def generate_test_case():
    # 随机生成字符串 S 和查询次数 Q
    S_length = random.randint(1, 200000)
    S = ''.join(random.choices(string.ascii_letters, k=S_length))
    Q = random.randint(1, 200000)
    
    # 随机生成 Q 个 K_i，每个范围为 [1, 10^18]
    K = [random.randint(1, 10**18) for _ in range(Q)]
    
    return S, Q, K

def run_program(program, input_data):
    try:
        # 调用外部程序并传递输入数据
        result = subprocess.run(program, input=input_data, text=True, capture_output=True, timeout=1)
        return result.stdout.strip()
    except subprocess.TimeoutExpired:
        return "TIMEOUT"

def main():
    for i in range(114514):
        # 生成测试数据
        S, Q, K = generate_test_case()
        
        # 格式化输入数据
        input_data = f"{S}\n{Q}\n" + ' '.join(map(str, K)) + '\n'
        
        # 获取两个程序的输出
        output_a = run_program("./a.out", input_data)
        output_b = run_program("./b.out", input_data)
        
        # 比较输出
        if output_a != output_b:
            print("Mismatch found!")
            print("Input data:")
            print(input_data)
            print("Output from a.out:")
            print(output_a)
            print("Output from b.out:")
            print(output_b)
            break
        else:
            print("ok")
    else:
        print("All test cases passed!")

if __name__ == "__main__":
    main()

