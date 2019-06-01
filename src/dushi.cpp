#include <stdio.h>
#include <ctype.h>
#include <cstring>
#include <cctype>
#include <iostream>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <vector>
#include <string>
#include <algorithm>

#include <dushi.h>

using namespace std;

bool DB_INIT = false;

unordered_map<string, entry> entries;

bool isCap(char c) { return (c >='A' && c <= 'Z'); }

vector<string> strspl(string &str, char token){
    vector<string> spl;
    istringstream f(str);
    string s;
    while (getline(f, s, token)) { spl.push_back(s); }
    return spl;
}

bool dushi_reload(){ return dushi_reload(""); }
bool dushi_reload(string path) {
    if(DB_INIT) entries.clear();
    return dushi_load(path);
}

bool dushi_load() { return dushi_load(""); }
bool dushi_load(string path) {
    if(path.empty()) path = "dushi.db";
    if(DB_INIT) return false;

    srand(time(nullptr));
    ifstream input(path);
    for(string line; getline(input, line);) {
        vector<string> spl = strspl(line, ',');
        if(spl.size() <= 0) continue;

        string key = spl[0].substr(0, spl[0].find('='));
        spl[0] = spl[0].substr(spl[0].find("=") + 1);
        entries[key] = entry{(int)spl.size(), spl};
    }

    DB_INIT = true;
    return DB_INIT;
}

string dushi_bezem(string str, int smileys=0, int aids=0) {
    string rtn;
    ostringstream buf;
    vector<string> spl = strspl(str, ' ');
    for(auto &word: spl) {
        int vsize = word.size();
        if(vsize <= 1) {
            buf << word << " ";
            continue;
        }

        string _orig_word = word;
        char last_char = word[vsize - 1];
        bool punct = last_char == '.';
        bool question = last_char == '?';
        if(punct || question) {
            word = word.substr(0, vsize - 1);
            vsize -= 1;
        }

        if(vsize <= 1) {
            buf << _orig_word << " ";
            continue;
        }

        bool cap = isCap(word[0]);
        std::transform(word.begin(), word.end(), word.begin(), ::tolower);

        if (entries.find(word) != entries.end()) {
            entry _entry = entries[word];
            if(_entry.count >= 1) {
                word = _entry.words[std::rand() % _entry.count];

                if(cap) word[0] = (char)toupper(word[0]);
                buf << word;

                if(punct || question) {
                    string suffix = punct ? ". " : "? ";

                    if(smileys && ((std::rand() % smileys) + 1) == smileys)
                        buf << " " << KUTSMILEYS[std::rand() % KUTSMILEYS.size()] << suffix;
                    else buf << suffix;
                }
                else buf << " ";
                continue;
            }
        }

        buf << _orig_word << " ";
    }

    string _buf = buf.str();
    rtn = _buf.substr(0, _buf.size() - 1);

    if(aids) {
        ostringstream aids_buf;
        for(char &c: rtn) {
            if(((std::rand() % aids) + 1) == aids && !isCap(c)) {
                aids_buf << (char)toupper(c);
                continue;
            }
            aids_buf << c;
        }
        rtn = aids_buf.str();
    }
    return rtn;
}
