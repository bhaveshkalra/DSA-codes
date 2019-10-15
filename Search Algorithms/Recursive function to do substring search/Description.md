# Recursive function to do substring search

Given a text txt[] and a pattern pat[], write a recursive function “contains(char pat[], char txt[])” that returns true if pat[] is present in txt[], otherwise false.

## Examples:

1) Input:   txt[] =  "THIS IS A TEST TEXT"
            pat[] = "TEST"
  Output:  true


2) Input:  txt[] =  "geeksforgeeks"
           pat[] = "quiz"
  Output:  false;

## Below is recursive algorithm.

contains(tex[], pat[])
    1) If the current character is the last character of the text, but pat
       has more characters, return false.

    2) Else If the current character is the last character of the pattern,
       then return true

    3) Else If current characters of pat and text match, then
        return contains(text + 1, pat + 1);

    4) Else If current characters of pat and text don't match
        return contains(text + 1, pat);
