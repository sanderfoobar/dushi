#ifndef DUSHI_H
#define DUSHI_H

#include <stdio.h>
#include <ctype.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

const vector<string> KUTSMILEYS = {";$",":$",":P",":ppp","xD",";P!!", ";-)!", "\\(^_._^)/!", ";-O", ":3333"};

struct entry {
    int count;
    vector<string> words;
};

bool isCap(char c);
vector<string> strspl(string &str, char token);
bool dushi_reload();
bool dushi_reload(string path);
bool dushi_load();
bool dushi_load(string path);
string dushi_bezem(string str, int smileys, int aids);

#endif // DUSHI_H
