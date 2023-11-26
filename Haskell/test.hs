isodd' :: Int -> String
isodd' 0 = "only accept positive integers"
isodd' y
    | num == 0 = "even"
    | num /= 0 = "odd"
    where num = y `mod` 2

main :: IO()
main = do
    input <- getLine
    let number = read input :: Int
    putStrLn (isodd' number)


