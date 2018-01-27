def dec(ch):
    return ord(ch) - ord('a') + 1


class RollingHash():
    def __init__(self, word, length):
        self.hash = 0
        self.length = length
        print(self.length)
        print(word[0:length])
        for i in range(0, length):
            self.hash += dec(word[i]) * 26 ** (length - 1 - i)

    def moveWindow(self, new, old):
        self.hash = (self.hash * 26) - (dec(old) *
                                        (26 ** (self.length))) + dec(new)


test = "ahello iam athul"
word = "hello"

wordR = RollingHash(word, len(word))
testR = RollingHash(test[0:len(word)], len(word))

for i in range(0, len(test) - len(word)):
    print(wordR.hash, testR.hash)
    if(wordR.hash == testR.hash):
        print("Found at ", i)
        break
    print(test[i + len(word)], test[i])
    testR.moveWindow(test[i + len(word)], test[i])
