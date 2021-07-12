intervals <- bridge()

test_that('bottomSet is correct for bridge', {
  expect_equal(length(bottomSet(intervals, 1)), 2)
  expect_equal(length(bottomSet(intervals, 2)), 3)
  expect_equal(length(bottomSet(intervals, 3)), 4)
  expect_equal(length(bottomSet(intervals, 3)), 4)
})

test_that('canonicalize is correct for bridge', {
  canon <- canonicalize(intervals)
  expect_true(all(toMatrix(canon) == toMatrix(intervals)))

  endpoints <- unique(c(canon[, 'left'], canon[, 'right']))
  expect_equal(length(endpoints), 2 * nrow(intervals))
})

test_that('cover graph is correct for bridge', {
  cg <- coverGraph(intervals)
  expect_equal(length(cg), 2)
  expect_equal(length(cg[[1]]), 1)
  expect_equal(cg[[1]][1], '3')
  expect_equal(length(cg[[2]]), 1)
  expect_equal(cg[[2]][1], '4')
})

test_that('indexIntervals is correct for bridge', {
  cis <- indexIntervals(intervals)
  expect_true(all(cis[, 'left'] == c(1, 1, 2, 3)))
  expect_true(all(cis[, 'right'] == c(4, 2, 3, 4)))
})

test_that('isCompatible is correct for bridge', {
  expect_true(isCompatible(intervals, c(1, 2, 3, 4)))
  expect_true(isCompatible(intervals, c(2, 1, 3, 4)))
  expect_true(isCompatible(intervals, c(2, 3, 1, 4)))
  expect_true(isCompatible(intervals, c(2, 3, 4, 1)))

  expect_false(isCompatible(intervals, c(1, 2, 4, 3)))
  expect_false(isCompatible(intervals, c(1, 3, 2, 4)))
  expect_false(isCompatible(intervals, c(1, 3, 4, 2)))
  expect_false(isCompatible(intervals, c(1, 4, 2, 3)))
  expect_false(isCompatible(intervals, c(1, 4, 3, 2)))
  expect_false(isCompatible(intervals, c(2, 1, 4, 3)))
  expect_false(isCompatible(intervals, c(2, 4, 1, 3)))
  expect_false(isCompatible(intervals, c(2, 4, 3, 1)))
  expect_false(isCompatible(intervals, c(3, 1, 2, 4)))
  expect_false(isCompatible(intervals, c(3, 1, 4, 2)))
  expect_false(isCompatible(intervals, c(3, 2, 1, 4)))
  expect_false(isCompatible(intervals, c(3, 2, 4, 1)))
  expect_false(isCompatible(intervals, c(3, 4, 1, 2)))
  expect_false(isCompatible(intervals, c(3, 4, 2, 1)))
  expect_false(isCompatible(intervals, c(4, 1, 2, 3)))
  expect_false(isCompatible(intervals, c(4, 1, 3, 2)))
  expect_false(isCompatible(intervals, c(4, 2, 1, 3)))
  expect_false(isCompatible(intervals, c(4, 2, 3, 1)))
  expect_false(isCompatible(intervals, c(4, 3, 1, 2)))
  expect_false(isCompatible(intervals, c(4, 3, 2, 1)))
})

test_that('lessThan is correct for bridge', {
  expect_false(lessThan(intervals, 1, 2))
  expect_false(lessThan(intervals, 1, 3))
  expect_false(lessThan(intervals, 1, 4))
  expect_false(lessThan(intervals, 2, 1))
  expect_false(lessThan(intervals, 3, 1))
  expect_false(lessThan(intervals, 4, 1))

  expect_true(lessThan(intervals, 2, 3))
  expect_true(lessThan(intervals, 2, 4))
  expect_true(lessThan(intervals, 3, 4))
})

test_that('partitions is correct for bridge', {
  expect_equal(length(partition(intervals)$partitions), 1)
})

test_that('topSet is correct for bridge', {
  expect_equal(length(topSet(intervals, 1)), 2)
  expect_equal(length(topSet(intervals, 2)), 3)
  expect_equal(length(topSet(intervals, 3)), 4)
  expect_equal(length(topSet(intervals, 3)), 4)
})
