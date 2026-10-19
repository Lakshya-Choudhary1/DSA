#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class TrieNode
{

public:
     char data;
     unordered_map<int, TrieNode *> children;
     bool isTerminal;

     TrieNode(char data) : data(data)
     {
          isTerminal = false;
     }
};

class Trie
{

     TrieNode *root;

public:
     //solve using loop
     void push(string data)
     {
          cout << "<----- INSERTING ----->" << endl;
          TrieNode* it = this->root;

          for(char c : data){
               //if present move it to the node
               if(it->children.count(c) == 1){ // 1 means true
                    it = it->children[c];
               }else{//if not fount create node and insert into it's children
                    it->children[c] = new TrieNode(c);
                    it = it->children[c];
               }
          }

          it->isTerminal = true;
          cout << "Data : " << data << " is inserted in trie." << endl;
     }

     void search(string data)
     {
          cout << "<----- SEARCHING ----->" << endl;
          TrieNode* it = this->root;

          for(char ch : data){
               if(it->children.count(ch) == 1){//present then move it to next char
                    it = it->children[ch];
               }else{
                    cout << "Data : " << data << " is not present in trie." << endl;
                    return ;
               }
          }

          if(it->isTerminal){
               cout << "Data : " << data << " is present in trie." << endl;
          }else{
               cout << "Data : " << data << " is not present in trie." << endl;
          }


     }

     void pop(string data)
     {
          TrieNode* it = this->root;

          for(char ch : data){
               if(it->children.count(ch) == 1){
                    it = it->children[ch];
               }else{
                    return ;
               }
          }

          if(it->isTerminal){
               it->isTerminal = false;
          }

          cout << "Data " << data << " is deleted from trie" << endl;

     }

     void startWithHelper(TrieNode* root , string word , vector<string>& words)
     {
          if(root->isTerminal == true)
          {
               words.push_back(word);
          }

          for(auto it : root->children)
          {
               word.push_back(char(it.first));
               startWithHelper(it.second , word , words);
               word.pop_back();
          }
     }

     void startWith(string word)
     {
          TrieNode* it = this->root;

          vector<string> words;
          string temp;
          

          for(char ch : word)
          {
               if(it->children.count(ch))
               {
                    temp.push_back(ch);
                    it = it->children[ch];
               }else
               {
                    break;
               }
          }

          startWithHelper(it,word,words);

          for(auto w : words)
          {
               cout << w << "\n" ;
          }

     }

     Trie()
     {
          this->root = new TrieNode('-');
     }
};

int main()
{

     Trie trie;

     trie.push("cat");
     trie.push("car");
     trie.push("cdb");

     trie.startWith("ca");


     return 0;
}