package main

func isVowel(w rune) bool {
	if w == 'a' || w == 'e' || w == 'i' || w == 'o' || w == 'u' {
		return true
	} else if w == 'A' || w == 'E' || w == 'I' || w == 'O' || w == 'U' {
		return true
	} else {
		return false
	}
}

func reverseVowels(s string) string {
	words := []rune(s)
	for i, j := 0, len(words)-1; ; {
		for ; i < j && !isVowel(words[i]); i++ {
		}
		for ; i < j && !isVowel(words[j]); j-- {
		}
		if i < j {
			words[i], words[j] = words[j], words[i]
			i, j = i+1, j-1
		} else {
			break
		}
	}
	return string(words)
}
