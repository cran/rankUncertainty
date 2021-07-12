intervals <- canonicalize(integers())

test_that('bottomSet is correct for integers', {
  expect_equal(length(bottomSet(intervals, 1)), 3)
  expect_equal(length(bottomSet(intervals, 2)), 4)
  expect_equal(length(bottomSet(intervals, 3)), 5)
  expect_equal(length(bottomSet(intervals, 4)), 5)
  expect_equal(length(bottomSet(intervals, 5)), 5)
})

test_that('canonicalize is correct for integers', {
  expect_true(all(toMatrix(intervals) == toMatrix(integers())))

  endpoints <- unique(c(intervals[, 'left'], intervals[, 'right']))
  expect_equal(length(endpoints), 2 * nrow(integers()))
})

test_that('cover graph is correct for integers', {
  cg <- coverGraph(intervals)
  expect_equal(length(cg), 2)
  expect_equal(length(cg[[1]]), 2)
  expect_equal(cg[[1]][1], '4')
  expect_equal(cg[[1]][2], '5')
  expect_equal(length(cg[[2]]), 1)
  expect_equal(cg[[2]][1], '5')
})

test_that('indexIntervals is correct for integers', {
  cis <- indexIntervals(intervals)
  expect_true(all(cis[, 'left'] == c(1, 1, 1, 2, 3)))
  expect_true(all(cis[, 'right'] == c(3, 4, 5, 5, 5)))
})

test_that('isCompatible is correct for integers', {
  expect_true(isCompatible(intervals, c(1, 2, 3, 4, 5)))
  expect_true(isCompatible(intervals, c(1, 2, 3, 5, 4)))
  expect_true(isCompatible(intervals, c(1, 2, 5, 3, 4)))

  expect_false(isCompatible(intervals, c(1, 5, 2, 3, 4)))
  expect_false(isCompatible(intervals, c(4, 1, 2, 3, 5)))
  expect_false(isCompatible(intervals, c(1, 3, 5, 2, 4)))
})

test_that('lessThan is correct for integers', {
  expect_true(lessThan(intervals, 1, 4))
  expect_true(lessThan(intervals, 1, 5))
  expect_true(lessThan(intervals, 2, 5))

  for (i in 1:nrow(intervals))
  {
    expect_false(lessThan(intervals, 3, i))
  }
})

test_that('partitions is correct for integers', {
  p <- partition(intervals)
  expect_equal(length(p$partitions), 1)
})

test_that('topSet is correct for integers', {
  expect_equal(length(topSet(intervals, 1)), 3)
  expect_equal(length(topSet(intervals, 2)), 4)
  expect_equal(length(topSet(intervals, 3)), 5)
  expect_equal(length(topSet(intervals, 4)), 5)
  expect_equal(length(topSet(intervals, 5)), 5)
})

