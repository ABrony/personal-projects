
def egcd(a, b):
    if a == 0:
        return (b, 0, 1)
    else:
        g, y, x = egcd(b % a, a)
        return (g, x - (b // a) * y, y)

def modinv(a, m):
    g, x, y = egcd(a, m)
    if g != 1:
        raise Exception('modular inverse does not exist')
    else:
        return x % m
    
p = 287319905035354589453095371815269475779
q = 291539480901443869518157426368349654241
e = 7
n = p*q
f = (p-1)*(q-1)
print(f"n: {n}\nf: {f}")
d = modinv(e,f)
print(f"Public key: e:{e}\nn:{n}\nPrivate key: d:{d}\nn:{n}")
data = 1337
print(f"Data: {data}")
cdata = pow(1337, e, n)
print(f"Ciphered data: {cdata}")

#if cdata < n then possible following:
print(f"Deciphered data with e = 3: {pow(cdata, 1./3.)}")
print(f"Deciphered data with e = 5: {pow(cdata, 1./5.)}")
print(f"Deciphered data with e = 7: {pow(cdata, 1./7.)}")
