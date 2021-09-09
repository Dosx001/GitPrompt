from os import system
def main():
    system("~/time.sh")
    with open('time.txt') as fp:
        lines = fp.readlines()
    avg = []
    while(len(lines) != 0):
        num1 = int(lines.pop())
        num2 = int(lines.pop())
        avg.append(abs(num2 - num1))
    print(sum(avg)/len(avg))

if __name__ == "__main__":
    main()
