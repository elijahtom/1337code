class Solution {
public:
    
    bool validate(string s, bool intcheck = false){
        vector<bool> valid(2,true); //isint, isdec
        
        bool one_dec_found = false;
        bool num_found = false;
        int i = 0;
        if(s[0] == '+' || s[0] == '-'){
            i++;
        }
        for(; i < s.length(); ++i){
            if(isdigit(s[i]) == false){
                valid[0] = false;
                if(s[i] == '.' && !one_dec_found){
                    one_dec_found = true;
                }
                else{
                    valid[1] = false;
                }
            }
            else if(!num_found){
                num_found = true;
            }
        }
        valid[0] = valid[0] && num_found;
        valid[1] = valid[1] && (one_dec_found && num_found);
        return (valid[0]||valid[1])&&(!intcheck) || (valid[0]&&intcheck);

    }

    bool isNumber(string s) {
        string dec_int = "";
        int j = 0;
        int s_length = s.length();
        while(tolower(s[j]) != 'e' && j < s_length){
            dec_int += s[j];
            j++;
        }
        if(dec_int.length() == 0 && s_length > 0){
            return false;
        }
        bool _or = validate(dec_int);
        if(j < s_length){
            if(j == s_length - 1){
                return false;
            }
            s = s.substr(j+1);
        }
        else{
            return _or;
        }
        return _or && validate(s,true);
    }
};