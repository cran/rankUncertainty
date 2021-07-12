intervals <- parts()

test_that('bottomSet is correct for parts', {
  expect_equal(length(bottomSet(intervals, 1)), 2)
  expect_equal(length(bottomSet(intervals, 2)), 2)
  expect_equal(length(bottomSet(intervals, 3)), 4)
  expect_equal(length(bottomSet(intervals, 4)), 4)
  expect_equal(length(bottomSet(intervals, 5)), 6)
  expect_equal(length(bottomSet(intervals, 6)), 6)
})

test_that('canonicalize is correct for parts', {
  canon <- canonicalize(intervals)
  expect_true(all(toMatrix(canon) == toMatrix(intervals)))

  endpoints <- unique(c(canon[, 'left'], canon[, 'right']))
  expect_equal(length(endpoints), 2 * nrow(intervals))
})

test_that('cover graph is correct for parts', {
  cg <- coverGraph(intervals)
  expect_equal(length(cg), 4)
  expect_equal(length(cg[[1]]), 2)
  expect_equal(cg[[1]][1], '3')
  expect_equal(length(cg[[2]]), 2)
  expect_equal(cg[[2]][1], '3')
  expect_equal(length(cg[[3]]), 2)
  expect_equal(cg[[3]][1], '5')
  expect_equal(length(cg[[4]]), 2)
  expect_equal(cg[[4]][1], '5')
})

test_that('indexIntervals is correct for parts', {
  cis <- indexIntervals(intervals)
  expect_true(all(cis[, 'left'] == c(1, 1, 3, 3, 5, 5)))
  expect_true(all(cis[, 'right'] == c(2, 2, 4, 4, 6, 6)))
})

test_that('isCompatible is correct for parts', {
  expect_true(isCompatible(intervals, c(1, 2, 3, 4, 5, 6)))
  expect_true(isCompatible(intervals, c(1, 2, 3, 4, 6, 5)))
  expect_true(isCompatible(intervals, c(2, 1, 3, 4, 5, 6)))
  expect_true(isCompatible(intervals, c(1, 2, 4, 3, 5, 6)))

  expect_false(isCompatible(intervals, c(1, 3, 2, 4, 5, 6)))
  expect_false(isCompatible(intervals, c(1, 2, 3, 5, 4, 6)))
  expect_false(isCompatible(intervals, c(6, 2, 3, 4, 5, 1)))
  expect_false(isCompatible(intervals, c(6, 5, 4, 3, 2, 1)))
})

test_that('lessThan is correct for parts', {
  expect_false(lessThan(intervals, 1, 2))
  expect_false(lessThan(intervals, 2, 1))
  expect_false(lessThan(intervals, 3, 1))
  expect_false(lessThan(intervals, 5, 2))

  expect_true(lessThan(intervals, 1, 3))
  expect_true(lessThan(intervals, 2, 5))
})


test_that('partitions is correct for parts', {
  p <- partition(intervals)
  expect_equal(length(p$partitions), 3)
  expect_true(all(p$partitions[[1]] == 1:2))
  expect_true(all(p$partitions[[2]] == 3:4))
  expect_true(all(p$partitions[[3]] == 5:6))
})

test_that('topSet is correct for parts', {
  expect_equal(length(topSet(intervals, 1)), 2)
  expect_equal(length(topSet(intervals, 2)), 2)
  expect_equal(length(topSet(intervals, 3)), 4)
  expect_equal(length(topSet(intervals, 4)), 4)
  expect_equal(length(topSet(intervals, 5)), 6)
  expect_equal(length(topSet(intervals, 6)), 6)
})
