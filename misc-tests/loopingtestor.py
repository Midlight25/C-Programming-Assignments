decision = None
while decision is None:
    print("Confirm that you would like to modify this file.")
    selection = input(">")
    if selection.lower() == "y":
        decision = True
    elif selection.lower() == "n":
        decision = False
    else:
        print("Invalid input, please try again \n")

print(decision)
