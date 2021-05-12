class Solution {
public:
    int myAtoi(string s) {
        int len = s.length();
        if(len == 0){
            return 0;
        }
        int j = 0;
        int sign = 1;
        while(s[j] == ' '){
            j++;
        }
        if(s[j] == '-' || s[j] == '+'){
            if(s[j] == '-'){
                sign = -1;   
            }   
            j++;
        }   
        string digits = "";
        while(j < len){
            if(isdigit(s[j])){
                digits += s[j];
                j++;
            }
            else{
                digits = digits.substr(0,j+1);
                break;
            }
        }
        j = 0;
        while(digits[j] == '0'){
            j++;
            if(j+1 < digits.length()){
                if(digits[j+1] != '0'){
                    digits = digits.substr(j);
                    break;
                }
            }
        }
        if(digits.length() == 0){
            return 0;
        }
        long int atoi = -1;
        int max = pow(2,31) -1;
        int min = -1*max -1;
        for(j = 0; j < digits.length(); ++j){
            int dig = digits[j] - '0';
            if(atoi == -1){
                atoi = dig;
            }
            else{
                if(j == 18){
                    if(sign < 0){
                        return min;
                    }
                    return max;
                    
                }
                atoi = atoi*10 + dig;
            }
        }
        atoi = atoi*sign;
        if(atoi > max){
            return max;
        }
        if(atoi < min){
            return min;
        }
        return atoi;
        
    }
};