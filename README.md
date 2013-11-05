A text of unknown length, but whose rows are limited to 1000 characters, is
stored in a file.

Write a C application able to evaluate the absolute frequency of all
strings appearing in the file.

More specifically the program has to:
* Receive on the command line two file names (input and output files).
* Read the input file and store all words with their relative
  frequency in a list.
  Capital and small letters has to be considered as equivalent
  (i.e., "WORD", "Word", and "word" are the same string).
* Store in the output file the list of words in any order.

------------------------------------------------------------
##Example:

- This is a correct input file

Mi illumino di immenso
Illumino di immenso
Di immenso
IMMENSO

- The output file has to be the following:

immenso 4
di 3
illumino 2
Mi 1