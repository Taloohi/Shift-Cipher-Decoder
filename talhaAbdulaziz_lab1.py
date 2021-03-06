A = [0.08167,
     0.01492,
     0.02782,
     0.04253,
     0.12702,
     0.02228,
     0.02015,
     0.06094,
     0.06996,
     0.00153,
     0.00772,
     0.04025,
     0.02406,
     0.06749,
     0.07507,
     0.01929,
     0.00095,
     0.05987,
     0.06327,
     0.09056,
     0.02758,
     0.00978,
     0.02360,
     0.00150,
     0.01974,
     0.00074]

Ai = [[0 for x in range(1)] for y in range(int((26)))] #Initialize an array that contains 25 arrays



text = "YUJLNJLXXUBRGCHCQXDBJWMBXRENQNJAMCQNUNJWVJWFQRBCUNMVAKDAWJKHFNWCXWCARDVYQJWCUHJWMCQNHBJHBQNUUQJENBYNWCJWXCQNABRGCHCQXDBJWMKNOXANBQNBORWRBQNMFRLTNMBJRMCQNUNJWVJWFQNANMBQNPNCJUUCQJCVXWNHOAXVJVNARLJBXRENQNJAMQNAVXCQNAFJBCQNXWUHMJDPQCNAXOXWNXOCQXBNVRUURXWJRANKUXTNBZDRCNURTNCQNYRLCDANBRBWCRCCQNPRAULJVNXDCXOCQNYXBCXOORLNJWMLURVKNMRWCXCQNLJAJBBQNMAXENXOOCQNUNJWVJWOXUUXFNMQNAFRCQQRBNHNBQNVDCCNANMRCBNNVBJUUFAXWPCXVNQNAUXXTRWPURTNCQJCVXWNHJWMUXXTBRCBCXXVDLQROJPRAUBJBARLQJBCQJCBQNBWXARPQCCXKNJPXXMUXXTNAJBFNUUJWMBQNRBJPXXMUXXTNAPXCNENAHCQRWPCQJCPRAUQJBMXNBWCBNNVOJRARRNGCAJLCOAXVCQNBXLRJULXUDVWXOCQNMJRUHKUJPDNJVXWPCQXBNBDYYRWPJCLQNIVJCJWCNRWXCRLNMKNJDCRODUURWWNCARMPNFJHBQNFJBFRCQCQNQXWSXJWWJBXDCQFXXMUXAMFRWMUNBQJVJWMVACXKHKAHLNVRBBARMPNFJHJBNENAHXWNTWXFBRBCQNMJDPQCNAXOVNUQDRBQARMPNFJHFQXVJAARNMJWWJQJACIBQNRWQNARCBOAXVQNAPAJWMOJCQNAUNXYXUMQJACIJWRVVNWBNOXACDWNCQNUXENUHURWWNCRBCQNBNWBJCRXWXOCQNVXVNWCJWMRCRBADVXDANMCQJCJWNWPJPNVNWCVJHKNJWWXDWLNMBQXACUHLNACJRWUHUXAMFRWMUNBQJVBNNVNMENAHYARBCQNQXWSXJWWJB"

alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"

W = []
prod = []
	

for i in range(0,26):
    Ai[i] = A[i::]+A[:i:] #circular shifts are added to 2D array
    W.append(text.count(alpha[i])/float(len(text))) #Vector W is created as specified

    
for i in range(0,26):
    summation = 0
    for j in range(0,25):
        summation += W[j]*Ai[i][j]
    prod.append(summation)

location = prod.index(max(prod))

key = alpha[location::]+alpha[:location:]


decipher = []

for ch in text:
    if ch in alpha: #checks if character belongs to alphabet
        decipher.append(key[alpha.index(ch)]) #add the index of the character to the same location in the key

new = ''.join(decipher) #convert list to string, uppercase string.


