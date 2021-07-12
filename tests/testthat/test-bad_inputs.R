test_that('intervals[, \'left\'] must be numeric', {
  left <- c('a', 'b', 'c', 'd')
  right <- 1:4
  intervals <- data.frame(left = left, right = right)
  expect_error(topSet(intervals))
})

test_that('intervals[, \'right\'] must be numeric', {
  left <- 1:4
  right <- c('b', 'c', 'd', 'e')
  intervals <- data.frame(left = left, right = right)
  expect_error(partition(intervals))
})

test_that('left must be in interval names', {
  left <- 1:4
  right <- left + 0.5
  intervals <- data.frame(x = left, y = right)
  expect_error(rankCIs(intervals))
})

test_that('right must be in interval names', {
  left <- 1:4
  right <- left + 0.5
  intervals <- data.frame(left = left, y = right)
  expect_error(partition(intervals))
})

test_that('columns must be ordered', {
  intervals <- generateIntervals(10)
  intervals[, 'left'] <- intervals[, 'left'] + 2
  expect_error(bottomSet(intervals, 5))
})

test_that('exactCount parameters must be correctly typed', {
  intervals <- generateIntervals(4)
  expect_error(exactCount(intervals, 'a'))
  expect_error(exactCount(intervals, cutoff = 'b'))
})

test_that('generateIntervals parameters must be correctly typed', {
  expect_error(generateIntervals('4'))
})

test_that('set functions require numeric k', {
  intervals <- generateIntervals(10)
  expect_error(bottomSet(intervals, 'a'))
  expect_error(topSet(intervals, 'b'))
})

test_that('transitiveReduction names must be the correct length', {
  intervals <- generateIntervals(10)
  expect_error(transitiveReduction(intervals, 1:9))
})
