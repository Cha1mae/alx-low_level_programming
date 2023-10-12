# 100-crackme.py
def main():
    password = "z"

    user_input = input("Enter the password: ")

    if user_input == password:
        print("OK")
    else:
        print("Incorrect password")

if __name__ == "__main__":
    main()
