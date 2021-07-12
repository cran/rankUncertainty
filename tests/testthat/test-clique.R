intervals <- clique()

test_that('bottomSet is correct for clique', {
  for (k in 1:10)
  {
    expect_equal(length(bottomSet(intervals, k)), 10)
  }
})

test_that('canonicalize is correct for clique', {
  canon <- canonicalize(intervals)
  expect_true(all(toMatrix(canon) == toMatrix(intervals)))

  endpoints <- unique(c(canon[, 'left'], canon[, 'right']))
  expect_equal(length(endpoints), 2 * nrow(intervals))
})

test_that('cover graph is correct for clique', {
  cg <- coverGraph(intervals)
  expect_equal(length(cg), 0)
})

test_that('indexIntervals is correct for clique', {
  cis <- indexIntervals(intervals)
  expect_true(all(cis[, 'left'] == rep(1, 10)))
  expect_true(all(cis[, 'right'] == rep(10, 10)))
})

test_that('isCompatible is correct for clique', {
  for (i in 1:50)
  {
    ranking <- sample(10)
    expect_true(isCompatible(intervals, ranking))
  }
})

test_that('lessThan is correct for clique', {
  n <- nrow(intervals)
  for (i in 1:n)
  {
    for (j in 1:n)
    {
      expect_false(lessThan(intervals, i, j))
    }
  }
})

test_that('partitions is correct for clique', {
  expect_equal(length(partition(intervals)$partitions), 1)
})

test_that('topSet is correct for clique', {
  for (k in 1:10)
  {
    expect_equal(length(topSet(intervals, k)), 10)
  }
})
