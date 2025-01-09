import subprocess
import random

def generate_random_LR():
    L = random.randint(1, 10**18)
    R = random.randint(L, 10**18)
    return L, R

def run_program(program, L, R):
    process = subprocess.run(
        [program],
        input=f"{L} {R}\n",  # 将 L 和 R 输入
        text=True,
        capture_output=True
    )
    return process.stdout.strip()  # 返回标准输出，去掉多余的空格和换行

def main():
    num_tests = 10000
    for i in range(num_tests):
        L, R = generate_random_LR()

        output_a = run_program("./a.out", L, R)
        output_b = run_program("./b.out", L, R)

        if output_a != output_b:
            print(f"Test {i + 1} failed:")
            print(f"L = {L}, R = {R}")
            print(f"a.out output: {output_a}")
            print(f"b.out output: {output_b}")
            return

    print("All tests passed!")

if __name__ == "__main__":
    main()

