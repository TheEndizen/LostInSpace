# translated "define" to a seven-letter shift
# align the decoder string with the alphabet
alphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"
upper = ""

# precondition: lineData is a string of characters

# file reader
file = open("Day17.ino")
lineData = file.readline()

for line in file:
    for character in alphabet:
        #print(character)
        if character.islower():
            pos = alphabet.find(character)
            lineData = lineData.replace(character, alphabet[(pos-7)%26])
        elif character.isupper():
            pos = upper.find(character)
            # ISSUE: need to modulus the entire string length for uppercase letters
            lineData = lineData.replace(character, alphabet[(pos-7)%26+26])
    print(lineData)
    lineData = file.readline()
