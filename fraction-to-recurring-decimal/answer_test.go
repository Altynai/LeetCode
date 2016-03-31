package main

import "testing"

func assert(t *testing.T, output string, expected string) {
	if output != expected {
		t.Fatal(output, expected)
	}
}

func TestFractionToDecimal(t *testing.T) {
	assert(t, fractionToDecimal(6, 17), "0.(3529411764705882)")
	assert(t, fractionToDecimal(1, 6), "0.1(6)")
	assert(t, fractionToDecimal(1, 3), "0.(3)")
	assert(t, fractionToDecimal(2, 1), "2")
	assert(t, fractionToDecimal(2, 5), "0.4")
	assert(t, fractionToDecimal(2, 3), "0.(6)")
	assert(t, fractionToDecimal(0, 3), "0")
	assert(t, fractionToDecimal(-22, -2), "11")
	assert(t, fractionToDecimal(-33, 3), "-11")
	assert(t, fractionToDecimal(-7, 12), "-0.58(3)")
	assert(t, fractionToDecimal(-1, -2147483648), "0.0000000004656612873077392578125")
}
