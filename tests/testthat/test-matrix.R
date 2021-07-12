test_that('toMatrix works with bridge', {
  M <- toMatrix(bridge())
  expect_true('matrix' %in% class(M))
  expect_equal(class(M[, 1]), 'logical')

  expect_equal(nrow(M), 4)
  expect_equal(ncol(M), 4)
  expect_true(all(apply(M, 1, sum) == c(0, 2, 1, 0)))
  expect_true(all(apply(M, 2, sum) == c(0, 0, 1, 2)))
})

test_that('toMatrix works with parts', {
  M <- toMatrix(parts(), strict = TRUE)
  expect_true('matrix' %in% class(M))
  expect_equal(class(M[, 1]), 'logical')

  expect_equal(nrow(M), 6)
  expect_equal(ncol(M), 6)
  expect_true(all(apply(M, 1, sum) == c(5, 5, 3, 3, 1, 1)))
  expect_true(all(apply(M, 2, sum) == c(1, 1, 3, 3, 5, 5)))
})

test_that('toMatrix works with simple', {
  M <- toMatrix(simple(), binary = TRUE)
  expect_true('matrix' %in% class(M))
  expect_true(checkNumericClass(M[, 1]))

  expect_equal(nrow(M), 3)
  expect_equal(ncol(M), 3)
  expect_true(all(apply(M, 1, sum) == c(1, 0, 0)))
  expect_true(all(apply(M, 2, sum) == c(0, 0, 1)))
})
