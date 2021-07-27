test_that('length of generated intervals is correct', {
  test <- function(i) {
    intervals <- generateIntervals(i)
    nrow(intervals) == i
  }

  expect_true(all(sapply(1:10, test)))
})

test_that('order of generated interval columns is correct',{
  test <- function() {
    intervals <- generateIntervals(5)
    all(intervals[, 'left'] <= intervals[, 'right'])
  }

  expect_true(all(replicate(100, test())))
})

test_that('length of transformed intervals is correct', {
  test <- function(i) {
    intervals <- generateIntervals(i, f = qnorm)
    nrow(intervals) == i
  }

  expect_true(all(sapply(1:10, test)))
})

test_that('order of transformed interval columns is correct', {
  test <- function() {
    intervals <- generateIntervals(5, f = qnorm)
    all(intervals[, 'left'] <= intervals[, 'right'])
  }

  expect_true(all(replicate(100, test())))
})

test_that('sort works correctly', {
  n <- 100
  intervals <- generateIntervals(n, sort = TRUE)
  idx <- 1:(n - 1)
  expect_true(all(intervals[idx, 'left'] <= intervals[idx + 1, 'left']))
})

test_that('canonicalize works correctly', {
  test <- function()
  {
    truth <- generateIntervals(10)
    test <- canonicalize(truth)
    all(toMatrix(truth) == toMatrix(test))
  }

  expect_true(all(replicate(100, test())))
})

test_that('canonicalize generates distinct endpoints', {
  test <- function()
  {
    intervals <- canonicalize(generateIntervals(10))
    endpoints <- unique(c(intervals[, 'left'], intervals[, 'right']))
    length(endpoints) == 2 * nrow(intervals)
  }

  expect_true(all(replicate(100, test())))
})
