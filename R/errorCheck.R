errorCheck <- function(intervals, strict = TRUE)
{

  if ('left' %notin% names(intervals))
  {
    stop('names(intervals) does not contain \'left\'')
  }
  if ('right' %notin% names(intervals))
  {
    stop('names(intervals) does not contain \'right\'')
  }
  if (!checkNumericClass(intervals[, 'left']))
  {
    stop('intervals[, \'left\'] is not integer or numeric')
  }
  if (!checkNumericClass(intervals[, 'right']))
  {
    stop('intervals[, \'right\'] is not integer or numeric')
  }
  if (strict)
  {
    if (any(intervals[, 'right'] <= intervals[, 'left']))
    {
      stop('intervals[, \'right\'] <= intervals[, \'left\'] for some values')
    }
  }
}

`%notin%` <- Negate(`%in%`)

checkNumericClass <- function(x)
{
  class(x) %in% c('integer', 'numeric')
}

