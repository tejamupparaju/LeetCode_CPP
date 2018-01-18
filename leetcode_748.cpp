/*
748. Shortest Completing Word

Find the minimum length word from a given dictionary words, which has all the letters from the string licensePlate. Such a word is said to complete the given string licensePlate

Here, for letters we ignore case. For example, "P" on the licensePlate still matches "p" on the word.

It is guaranteed an answer exists. If there are multiple answers, return the one that occurs first in the array.

The license plate might have the same letter occurring multiple times. For example, given a licensePlate of "PP", the word "pair" does not complete the licensePlate, but the word "supper" does.

Example 1:
Input: licensePlate = "1s3 PSt", words = ["step", "steps", "stripe", "stepple"]
Output: "steps"
Explanation: The smallest length word that contains the letters "S", "P", "S", and "T".
Note that the answer is not "step", because the letter "s" must occur in the word twice.
Also note that we ignored case for the purposes of comparing whether a letter exists in the word.
Example 2:
Input: licensePlate = "1s3 456", words = ["looks", "pest", "stew", "show"]
Output: "pest"
Explanation: There are 3 smallest length words that contains the letters "s".
We return the one that occurred first.
Note:
licensePlate will be a string with length in range [1, 7].
licensePlate will contain digits, spaces, or letters (uppercase or lowercase).
words will have a length in the range [10, 1000].
Every words[i] will consist of lowercase letters, and have length in range [1, 15].
*/

#include <map>
class Solution {
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        vector<char> license_plate; 
        for(int i=0; i<licensePlate.length(); i++){
            if (isalpha(licensePlate[i]))
                license_plate.push_back(tolower(licensePlate[i]));
        }
        vector<map<char, int>> words_map;
        map<char, int> tmap;
        for(int i=0; i<words.size(); i++){
            for (int j=0; j<words[i].length(); j++){
                tmap[words[i][j]] += 1;
            }
            words_map.push_back(tmap);
            tmap.clear();    
        }
        
        bool flag;
        int result, maxer=0;
        for(int i=0; i<words.size(); i++){
            flag = true;
            for(int j=0; j<license_plate.size(); j++){
                if (words_map[i].find(license_plate[j]) != words_map[i].end() and words_map[i][license_plate[j]] > 0)
                    words_map[i][license_plate[j]] -= 1;
                else{
                    flag = false;
                    break;
                }
            }
            if (flag){
                if (maxer == 0 ||  maxer > words[i].length()){
                    result = i;
                    maxer = words[i].length();
                }
                }
            }
         
        return words[result];
        }        
        
    };
