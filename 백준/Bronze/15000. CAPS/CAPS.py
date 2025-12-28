import sys
inputdata = sys.stdin.readline

def fnToUpperCase(text):
    upperText = text.upper()
    print(upperText)

if __name__ == "__main__":
    text = str(inputdata().strip())
    
    fnToUpperCase(text)