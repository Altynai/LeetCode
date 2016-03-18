
package main

import "testing"

func TestCountBits(t *testing.T) {
    expected := []int{0, 1, 1, 2, 1, 2}
    result := countBits(5)
    for i := 0; i < len(expected); i++ {
        if result[i] != expected[i] {
            t.Fatalf("Expected %d, got %d", expected[i], result[i])
        }
    }
}
