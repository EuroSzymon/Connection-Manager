import importlib
import subprocess
import time

def main():
    while True:
        importlib.reload(subprocess)
        time.sleep(1)

if __name__ == "__main__":
    main()