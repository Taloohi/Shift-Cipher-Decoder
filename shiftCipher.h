#include <iostream>
#include <string>
#include<bits/stdc++.h>

using namespace std;

int main()
{
    string text = "YUJLNJLXXUBRGCHCQXDBJWMBXRENQNJAMCQNUNJWVJWFQRBCUNMVAKDAWJKHFNWCXWCARDVYQJWCUHJWMCQNHBJHBQNUUQJENBYNWCJWXCQNABRGCHCQXDBJWMKNOXANBQNBORWRBQNMFRLTNMBJRMCQNUNJWVJWFQNANMBQNPNCJUUCQJCVXWNHOAXVJVNARLJBXRENQNJAMQNAVXCQNAFJBCQNXWUHMJDPQCNAXOXWNXOCQXBNVRUURXWJRANKUXTNBZDRCNURTNCQNYRLCDANBRBWCRCCQNPRAULJVNXDCXOCQNYXBCXOORLNJWMLURVKNMRWCXCQNLJAJBBQNMAXENXOOCQNUNJWVJWOXUUXFNMQNAFRCQQRBNHNBQNVDCCNANMRCBNNVBJUUFAXWPCXVNQNAUXXTRWPURTNCQJCVXWNHJWMUXXTBRCBCXXVDLQROJPRAUBJBARLQJBCQJCBQNBWXARPQCCXKNJPXXMUXXTNAJBFNUUJWMBQNRBJPXXMUXXTNAPXCNENAHCQRWPCQJCPRAUQJBMXNBWCBNNVOJRARRNGCAJLCOAXVCQNBXLRJULXUDVWXOCQNMJRUHKUJPDNJVXWPCQXBNBDYYRWPJCLQNIVJCJWCNRWXCRLNMKNJDCRODUURWWNCARMPNFJHBQNFJBFRCQCQNQXWSXJWWJBXDCQFXXMUXAMFRWMUNBQJVJWMVACXKHKAHLNVRBBARMPNFJHJBNENAHXWNTWXFBRBCQNMJDPQCNAXOVNUQDRBQARMPNFJHFQXVJAARNMJWWJQJACIBQNRWQNARCBOAXVQNAPAJWMOJCQNAUNXYXUMQJACIJWRVVNWBNOXACDWNCQNUXENUHURWWNCRBCQNBNWBJCRXWXOCQNVXVNWCJWMRCRBADVXDANMCQJCJWNWPJPNVNWCVJHKNJWWXDWLNMBQXACUHLNACJRWUHUXAMFRWMUNBQJVBNNVNMENAHYARBCQNQXWSXJWWJB"
;
    string alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    
 
  
    float A[26] = {0.08167,
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
     0.00074};
    
    float Ai[26][26];
    
    
    
    for(int i = 0; i < 26; i++){
        Ai[0][i] = A[i];
        }
        
    for (int i = 1; i < 26; i ++){
        float place = Ai[i-1][0];
        for (int j = 0; j < 25; j++){
            Ai[i][j] = Ai[i-1][j+1];
            } 
        Ai[i][25] = place; 
        }
        
    
    float W[26] = {};
    for (int i = 0; i < text.length(); i ++){
        for (int j = 0; j < 26; j++){
            if (text[i] == alpha[j]){
                W[j] += 0.001;
                }
            }
        }
    
    float prod[26];
    for (int i = 0; i < 26; i ++){
        float sum = 0;
        for (int j = 0; j < 25; j++){
            sum = sum + W[j]*Ai[i][j];
            } 
        prod[i] = sum; 
        }
    
    
    int max = 0;
    for (int i = 0; i < 26; i ++){
    
        if (prod[i]>prod[max]){
            max = i;
            } 
        }
    
    string key = alpha;
    reverse(key.begin(), key.begin()+max);
    reverse(key.begin()+max, key.end());
    reverse(key.begin(), key.end());
    
    string decipher[text.length()];
    
    for (int i = 0; i < text.length(); i++){
        for(int j = 0; j < 26; j++){
            if(text[i]==alpha[j]){
                decipher[i] = key[j];
                }
            
            
            }
        
        
        }
    
    for (int i = 0; i < text.length(); i++){
        cout << decipher[i];
        }    
     
}
