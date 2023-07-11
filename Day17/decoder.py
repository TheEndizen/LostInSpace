# translated "define" to a seven-letter shift
# align the decoder string with the alphabet
alphabet = "abcdefghijklmnopqrstuvwxyz"
upper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"

# precondition: lineData is a string of characters

# file reader
file = open("Day17.ino")
lineData = ""

for line in file:
    for character in alphabet:
        #print(character)
        if character.islower():
            pos = alphabet.find(character)
            lineData = lineData.replace(character, alphabet[(pos+19)%26])
        elif character.isupper():
            pos = upper.find(character)
            lineData = lineData.replace(character, upper[pos+19]%26)
    print(lineData)
    lineData = file.readline()
