intervals <- simple()

test_that('bottomSet is correct for simple intervals', {
  expect_equal(length(bottomSet(intervals, 1)), 2)
  expect_equal(length(bottomSet(intervals, 2)), 3)
  expect_equal(length(bottomSet(intervals, 3)), 3)
})

test_that('canonicalize is correct for simple intervals', {
  canon <- canonicalize(intervals)
  expect_true(all(toMatrix(canon) == toMatrix(intervals)))

  endpoints <- unique(c(canon[, 'left'], canon[, 'right']))
  expect_equal(length(endpoints), 2 * nrow(intervals))
})

test_that('cover graph is correct for simple intervals', {
  cg <- coverGraph(intervals)
  expect_equal(length(cg), 1)
  expect_equal(length(cg[[1]]), 1)
  expect_equal(cg[[1]][1], '3')
})

test_that('indexIntervals is correct for simple intervals', {
  cis <- indexIntervals(intervals)
  expect_true(all(cis[, 'left'] == c(1, 1, 2)))
  expect_true(all(cis[, 'right'] == c(2, 3, 3)))
})

test_that('isCompatible is correct for simple intervals', {
  expect_true(isCompatible(intervals, c(1, 2, 3)))
  expect_true(isCompatible(intervals, c(1, 3, 2)))
  expect_true(isCompatible(intervals, c(2, 1, 3)))

  expect_false(isCompatible(intervals, c(2, 3, 1)))
  expect_false(isCompatible(intervals, c(3, 1, 2)))
  expect_false(isCompatible(intervals, c(3, 2, 1)))
})

test_that('lessThan is correct for simple intervals', {
  expect_false(lessThan(intervals, 1, 1))
  expect_false(lessThan(intervals, 1, 2))
  expect_false(lessThan(intervals, 2, 1))
  expect_false(lessThan(intervals, 2, 2))
  expect_false(lessThan(intervals, 2, 3))
  expect_false(lessThan(intervals, 3, 1))
  expect_false(lessThan(intervals, 3, 2))
  expect_false(lessThan(intervals, 3, 3))

  expect_true(lessThan(intervals, 1, 3))
})

test_that('partitions is correct for simple intervals', {
  expect_equal(length(partition(intervals)$partitions), 1)
})

test_that('topSet is correct for simple intervals', {
  expect_equal(length(topSet(intervals, 1)), 2)
  expect_equal(length(topSet(intervals, 2)), 3)
  expect_equal(length(topSet(intervals, 3)), 3)
})
