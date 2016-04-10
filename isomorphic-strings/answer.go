func isIsomorphic(s string, t string) bool {
	if len(s) != len(t) {
		return false
	}
	dict := make(map[byte]byte)
	mapped := make(map[byte]byte)
	for i := 0; i < len(s); i++ {
		s_word := s[i]
		t_word := t[i]
		if d_word, ok := dict[s_word]; ok && d_word != t_word {
			return false
		}
		if r_word, ok := mapped[t_word]; ok && r_word != s_word {
			return false
		}
		dict[s_word] = t_word
		mapped[t_word] = s_word
	}
	return true
}