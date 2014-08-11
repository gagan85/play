-- Author: Sam Zhao
-- Email: sam@cs.brown.edu
-- http://www.haskell.org/haskellwiki/99_questions/1_to_10

-- P1: Find the last element of a list.
myLast [x] = x
myLast (_:xs) = myLast xs

-- P2: Find the last but one element of a list.
myButLast [x,_] = x
myButLast (_:xs) = myButLast xs

-- P3: Find the K'th element of a list. The first element in the list is number 1.
elementAt (x:_) 1 = x
elementAt (_:xs) index = elementAt xs $ index - 1

-- P4: Find the number of elements of a list.
myLength [] = 0
myLength (_:xs) = 1 + myLength xs

-- P5: Reverse a list.
myReverse [] = []
myReverse (x:xs) = (myReverse xs) ++ [x]

-- P6: Fidn out whether a list is a palindrome.
isPalindrome [] = True
isPalindrome [x] = True
isPalindrome (x:xs) = x == last xs && isPalindrome (init xs)

-- P7: Flatten a nested list structure.


-- P8: Eliminate consecutive duplicates of list elements.
compress [x] = [x]
compress (x:xs) = firstSlice ++ compress xs 
    where 
        firstSlice = 
            if x == head xs 
                then [] 
                else [x]

-- P9: Pack consecutive duplicates of list elements into sublists.
-- TODO: improve
pack (x:xs) = pack' [] [x] xs
    where
        pack' doneSublists wipSublist [] = doneSublists ++ [wipSublist]
        pack' doneSublists wipSublist (x:xs) = 
            pack' updatedDoneSublists updatedWipSublist xs
                where 
                    updatedWipSublist = 
                        if head wipSublist == x 
                            then x:wipSublist
                            else [x]
                    updatedDoneSublists = 
                        if head wipSublist == x
                            then doneSublists
                            else doneSublists ++ [wipSublist]

-- P10: Run-length encoding of P9
encode (x:xs) = countPacked . pack $ x:xs
countPacked xss = [(length xs, head xs) | xs <- xss]
