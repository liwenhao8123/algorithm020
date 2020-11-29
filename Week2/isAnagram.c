//由于小写字符总共26个，引入int t[26]，相当于26个元素的hash表，计算s中存在的字符则++，而t中有相同的字符则--

bool isAnagram(char * s, char * t){
    int len_s = strlen(s);
    int len_t = strlen(t);
    if (len_s != len_t)
        return false;
    int table[26] = {0};
    for (int i = 0; i < len_s; i++){
        table[s[i] - 'a']++;
        table[t[i] - 'a']--;
    }
    for (int i = 0; i < 26; i++){
        if (table[i] != 0)
            return false;
    }
    return true;
}