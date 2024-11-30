def FizzBuzz(n):
    answer = []

    for i in range (1, n+1):
        if i%3 == 0 and i%5 == 0:
            answer.append('Fizzbuzz')
        elif i%3 == 0:
            answer.append('Fizz')
        elif i%5 == 0:
            answer.append('Buzz')
        else:
            answer.append(str(i))
        
    print(answer)




FizzBuzz(30)
        