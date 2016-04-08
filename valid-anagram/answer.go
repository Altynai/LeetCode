func isAnagram(s string, t string) bool {
	if len(s) != len(t) {
		return false
	}
	s_counter := make(map[byte]int, 26)
	t_counter := make(map[byte]int, 26)
	for i := 0; i < len(s); i++ {
		s_counter[s[i]] += 1
		t_counter[t[i]] += 1
	}
	for k, v := range s_counter {
		if w, ok := t_counter[k]; !ok || v != w {
			return false
		}
	}
	return true
}