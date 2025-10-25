def power(base,exponent)
  if exponent == 0
    return 1
  elsif exponent < 0
    return nil
  end
  
  i = 1
  result = base
  while i < exponent
    result *= base
    i += 1
  end
  return result
end
