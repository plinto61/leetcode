/**
 * @param {string} s
 * @param {string} t
 * @return {boolean}
 */
var isAnagram = function(s, t) {
    if(s.length !== t.length) return false;
    const a = 'a'.charCodeAt(0);
    const l_map = Array(26).fill(0);
    for(let i=0; i<s.length; i++){
        l_map[s.charCodeAt(i)-a]++;
    }
    for(let i=0; i<t.length; i++){
        const idx = t.charCodeAt(i)-a
        l_map[idx]--;
        if(l_map[idx] < 0) return false;
    }
    return true;
};