

def harmonic(n: int, s: int) -> int:
    '''
    Computes and returns the nth generalized harmonic number.

    Parameters:
        n (int): order of the harmonic number
        s (int): exponent
    '''
    sum = 0
    for i in range(1, n+1):
        sum += 1 / pow(i, s)
    return sum

def zipf(rank: int, n: int, s: float) -> float:
    '''
    Computes the normalized frequency of rank k element.

    Zipf law is stated as f(k; N, s) = 1 / k^s Hn,s

    Parameters:
        rank (int): rank number of the word when the words are sorted according to their frequencies
        n (int): number of elements
        s (float): value of the exponent characterizing the distribution
    
    Returns:
        float: the normalized frequency of rank k
    '''
    zip_val: float = 1 / (pow(rank, s) * harmonic(n, s))
    return zip_val


def main() -> None:
    n: int = 10
    s: float = 1.0
    sum: float = 0.0
    for i in range(1, 11):
        sum += zipf(i, n, s)
        print(f"Distribution {i}: {zipf(i, n, s)}")
    print(f"Sum of distributions: {sum}")
    return None



if __name__ == '__main__':
    main()