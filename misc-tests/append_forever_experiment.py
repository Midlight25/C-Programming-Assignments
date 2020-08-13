letters = ["A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M",
           "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z"]
points = [1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 4, 1, 3, 10, 1, 1, 1, 1, 4, 4,
          8, 4, 10]
letter_to_points = {key: value for key, value in zip(letters, points)}

for letter in letter_to_points.copy():
    letter_to_points[letter.lower()] = letter_to_points[letter]
    print("Added {letter} and {point} letter/point combination to \
letter_to_points.".format(letter=letter.lower(), point=letter_to_points[letter]))

for letter, point in letter_to_points.items():
    print(letter, point)
