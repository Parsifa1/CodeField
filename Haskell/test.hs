maximum' :: (Ord a) => [a] -> a
maximum' [] = error "maximum of empty list"
maximum' [x] = x
maximum' (x : xs) = max x (maximum' xs)

-- print $ (+ 1) $ length $ takeWhile (< 10000000) $ scanl1 (+) $ map sqrt [1 ..]

qsort :: (Ord a) => [a] -> [a]
qsort [] = []
qsort (x : xs) = qsort smaller ++ [x] ++ qsort larger
  where
    smaller = [a | a <- xs, a <= x]
    larger = [b | b <- xs, b > x]

main :: IO ()
main = do
    print $ qsort [9, 10, 13, 7, 14, 6, 18]
