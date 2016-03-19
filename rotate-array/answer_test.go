
package main

import "testing"

func assert(nums ,expected []int, t *testing.T) {
    for i := 0; i < len(expected); i++ {
        if nums[i] != expected[i] {
            t.Fatalf("Expected %d, got %d", expected[i], nums[i])
        }
    }    
}

func TestRotateCase1(t *testing.T) {
    expected := []int{5, 6, 7, 1, 2, 3, 4}
    nums := []int{1, 2, 3, 4, 5, 6, 7}
    rotate(nums, 3)
    assert(nums, expected, t)
}

func TestRotateCase2(t *testing.T) {
    nums := []int{1, 2, 3, 4, 5, 6}
    expected := []int{5, 6, 1, 2, 3, 4}
    rotate(nums, 2)
    assert(nums, expected, t)
}
