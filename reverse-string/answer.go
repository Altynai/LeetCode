package main

func reverseString(s string) string {
	words := []rune(s)
	for i, j := 0, len(words)-1; i < j; i, j = i+1, j-1 {
		words[i], words[j] = words[j], words[i]
	}
	return string(words)
}
