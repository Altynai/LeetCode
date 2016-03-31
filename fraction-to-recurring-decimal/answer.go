package main

import "fmt"

func abs(integer int) int {
	if integer < 0 {
		return -integer
	} else {
		return integer
	}
}

func divisionSimulation(numerator int, denominator int) (int, int) {
	numerator *= 10
	return numerator / denominator, numerator % denominator
}

func fractionToDecimal(numerator int, denominator int) string {
	if numerator == 0 {
		return "0"
	} else if numerator%denominator == 0 {
		return fmt.Sprintf("%d", numerator/denominator)
	}
	negative := ""
	if (numerator < 0 && denominator > 0) || (numerator > 0 && denominator < 0) {
		negative = "-"
		numerator = abs(numerator)
		denominator = abs(denominator)
	}
	base := fmt.Sprintf("%s%d.", negative, numerator/denominator)
	numerator %= denominator
	remainders := make(map[string]int)
	quotients := make([]int, 0)
	step, found := 0, -1
	for {
		quotient, remainder := divisionSimulation(numerator, denominator)
		quotients = append(quotients, quotient)
		if remainder == 0 {
			break
		}
		key := fmt.Sprintf("%d.%d", quotient, remainder)
		if index, ok := remainders[key]; ok {
			found = index
			break
		}
		numerator = remainder
		remainders[key] = step
		step += 1
	}
	if found != -1 {
		for i := 0; i < len(quotients)-1; i++ {
			if i == found {
				base = fmt.Sprintf("%s(", base)
			}
			base = fmt.Sprintf("%s%d", base, quotients[i])
			if i == len(quotients)-2 {
				base = fmt.Sprintf("%s)", base)
			}
		}
	} else {
		for i := 0; i < len(quotients); i++ {
			base = fmt.Sprintf("%s%d", base, quotients[i])
		}
	}
	return base
}
