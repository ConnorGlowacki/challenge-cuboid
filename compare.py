import subprocess
import os

def compare_binaries(bin1: str, bin2: str, *args):
    try:
        cmd1 = [bin1] + list(args)
        result1 = subprocess.check_output(cmd1, text=True, stderr=subprocess.STDOUT)

        cmd2 = [bin2] + list(args)
        result2 = subprocess.check_output(cmd1, text=True, stderr=subprocess.STDOUT)

        # print(result1)
        # print(result2)

        lines1 = result1.strip().splitlines()
        lines2 = result2.strip().splitlines()

        # Compare the lines
        if lines1 == lines2:
            print("The outputs match.")
        else:
            print("The outputs differ:")
            for i, (line1, line2) in enumerate(zip(lines1, lines2)):
                if line1 != line2:
                    print(f"Deviation at line {i + 1}:")
                    print(f"  Output1: {line1}")
                    print(f"  Output2: {line2}")
    except subprocess.CalledProcessError as e:
        print(f"Error while running binaries: {e}")

if __name__ == "__main__":
    binary_path1 = f"{os.getcwd()}/cuboid"
    binary_path2 = f"{os.getcwd()}/test"

    for i in range(1, 15):
        compare_binaries(binary_path1, binary_path2, str(i), str(i), str(i))
        compare_binaries(binary_path1, binary_path2, str(i), str(i+i), str(i))
        compare_binaries(binary_path1, binary_path2, str(i+i), str(i), str(i))
        compare_binaries(binary_path1, binary_path2, str(i), str(i), str(i+i))
