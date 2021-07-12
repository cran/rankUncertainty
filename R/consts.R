## Test cases ##
bridge <- function()
{
  left <- c(0, 1, 2.1, 3.2)
  right <- c(4.5, 2, 3.1, 4.2)
  data.frame(left = left, right = right)
}

clique <- function()
{
  left <- 0:9 / 10
  right <- left + 1
  data.frame(left = left, right = right)
}

integers <- function()
{
  left <- c(0, 0, 0, 1, 2)
  right <- c(0, 1, 2, 2, 2)
  data.frame(left = left, right = right)
}

parts <- function()
{
  left <- sort(c(1:3, 1:3 + 0.1))
  right <- left + 0.7
  data.frame(left = left, right = right)
}

simple <- function()
{
  left <- 0:2 * 0.5 + 1
  right <- left + 0.75
  data.frame(left = left, right = right)
}
