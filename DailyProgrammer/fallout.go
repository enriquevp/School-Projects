/*
 * Fallout.go
 * Simulates the terminal hacking minigame present in Fallout 3 and New Vegas
 *
 */

package main

import (
	"bufio"
	"fmt"
	"log"
	"math/rand"
	"os"
	"os/exec"
	"strings"
	"time" // Used to randomize the number generator
)

func readLines(path string) ([]string, error) {
	file, err := os.Open(path)
	if err != nil {
		return nil, err
	}
	defer file.Close()

	var lines []string
	scanner := bufio.NewScanner(file)

	for scanner.Scan() {
		lines = append(lines, scanner.Text())
	}

	return lines, scanner.Err()
}

func Difficulty(diff string) int {
	var diffLevel int

	switch diff {
	case "easiest":
		diffLevel = 0
	case "easy":
		diffLevel = 1
	case "average":
		diffLevel = 2
	case "hard":
		diffLevel = 3
	case "hardest":
		diffLevel = 4
	}

	return diffLevel
}

func getWords(lines []string, diffLevel int) ([]string, int) {
	var arraySize, wordLength int

	switch diffLevel {
	case 0:
		arraySize = 5
		wordLength = 4
	case 1:
		arraySize = 7
		wordLength = 5
	case 2:
		arraySize = 9
		wordLength = 7
	case 3:
		arraySize = 10
		wordLength = 10
	case 4:
		arraySize = 15
		wordLength = 15
	}

	var wordList = make([]string, 0)
	for len(wordList) < arraySize { // Fills the array
		appendWord := lines[(rand.Intn(172819))]
		if len(appendWord) == wordLength {
			wordList = append(wordList, appendWord)
		}
	}
	return wordList, arraySize
}

func checkWord(word string) (int, int) {
	var (
		rightCount, attempts int = 0, 0
		userWord             string
	)

	for rightCount != len(word) && attempts != 4 {
		fmt.Printf("Take your guess (lowercase) (%d remaining): ", 4-attempts)
		fmt.Scanf("%s\n", &userWord)
		rightCount = 0
		for i := range userWord {
			if userWord[i] == word[i] {
				rightCount++
			}
		}
		fmt.Printf("%d/%d correct\n", rightCount, len(word))
		attempts++
	}
	return rightCount, attempts
}

func main() {
	rand.Seed(time.Now().Unix())
	var diffLevel string

	lines, err := readLines("falloutdictionary.txt")
	if err != nil {
		log.Fatal(err)
	}

	// Menu
	fmt.Println("easiest")
	fmt.Println("easy")
	fmt.Println("average")
	fmt.Println("hard")
	fmt.Println("hardest")
	fmt.Printf("Input the desired difficulty level : ")
	fmt.Scanf("%s\n", &diffLevel)

	diffLevelint := Difficulty(diffLevel)
	gameList, arrLength := getWords(lines, diffLevelint)

	word := gameList[(rand.Intn(arrLength))] // Assign the winning word

	c := exec.Command("clear")
	c.Stdout = os.Stdout
	c.Run()

	for i := 0; i < len(gameList); i++ {
		fmt.Println(strings.ToUpper(gameList[i])) // Present the word list
	}

	rightCount, attempts := checkWord(word)

	if rightCount == len(word) {
		fmt.Println("Congratulations!")
	}

	if rightCount != len(word) && attempts == 4 {
		fmt.Println("Dang, you got no tries left...")
	}
}
