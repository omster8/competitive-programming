import random

def RandomizedMotifSearch(Dna, k, t):
    Current_Motifs = RandomMotifs(Dna, k, t)
    Best_Motifs = Current_Motifs
    while True:
        Profile = ProfileWithPseudocounts(Current_Motifs)
        Current_Motifs = Motifs(Profile, Dna)
        if Score(Current_Motifs) < Score(Best_Motifs):
            Best_Motifs = Current_Motifs
        else:
            return Best_Motifs
    
def RandomMotifs(Dna, k, t):
    random_motifs = []
    for i in range(len(Dna)):
        temp_rand_index = random.randint(0, len(Dna[0])-k)
        random_motifs.append(Dna[i][temp_rand_index:temp_rand_index + k])
    return random_motifs

def Motifs(Profile, Dna):
    most_probable_kmers = []
    for i in range(len(Dna)):
        most_probable_kmers.append(ProfileMostProbableKmer(Dna[i], len(Profile['A']), Profile))
    return most_probable_kmers

def Pr(Text, Profile):
    prob = 1.0
    for i in range(len(Text)):
        prob *= Profile[Text[i]][i]
    return prob

def ProfileMostProbableKmer(Text, k, Profile):
    highest_prob = 0
    most_prob_kmer = Text[0:k]
    for i in range(len(Text) - k + 1):
        if Pr(Text[i:i+k], Profile) > highest_prob:
            highest_prob = Pr(Text[i:i+k], Profile)
            most_prob_kmer = Text[i:i+k]
    return most_prob_kmer

def Consensus(Motifs):
    consensus = ""
    count = CountWithPseudocounts(Motifs)
    for i in range(len(Motifs[0])):
        highest_count = 0
        most_frequent = ""
        for char in "ACGT":
            if count[char][i] > highest_count:
                highest_count = count[char][i]
                most_frequent = char
        consensus += most_frequent
    return consensus

def ProfileWithPseudocounts(Motifs):
    t = len(Motifs)
    k = len(Motifs[0])
    profile = CountWithPseudocounts(Motifs)
    for char in "ACGT":
        for i in range(len(profile[char])):
            profile[char][i] = profile[char][i] / (4+len(Motifs))
    return profile

def CountWithPseudocounts(Motifs):
    count = {}
    for char in "ACGT":
        count[char] = []
    for i in range(len(Motifs[0])):
        for char in "ACGT":
            count[char].append(0)
    for i in range(len(Motifs)):
        for j in range(len(Motifs[0])):
            count[Motifs[i][j]][j] += 1
    for char in "ACGT":
        for i in range(len(count[char])):
            count[char][i] += 1
    return count

def Score(Motifs):
    consensus = Consensus(Motifs)
    score = 0
    for i in range(len(Motifs)):
        for j in range(len(Motifs[i])):
            if not Motifs[i][j] == consensus[j]:
                score += 1
    return score

Dna = ["GCGCCCCGCCCGGACAGCCATGCGCTAACCCTGGCTTCGATGGCGCCGGCTCAGTTAGGGCCGGAAGTCCCCAATGTGGCAGACCTTTCGCCCCTGGCGGACGAATGACCCCAGTGGCCGGGACTTCAGGCCCTATCGGAGGGCTCCGGCGCGGTGGTCGGATTTGTCTGTGGAGGTTACACCCCAATCGCAAGGATGCATTATGACCAGCGAGCTGAGCCTGGTCGCCACTGGAAAGGGGAGCAACATC",
"CCGATCGGCATCACTATCGGTCCTGCGGCCGCCCATAGCGCTATATCCGGCTGGTGAAATCAATTGACAACCTTCGACTTTGAGGTGGCCTACGGCGAGGACAAGCCAGGCAAGCCAGCTGCCTCAACGCGCGCCAGTACGGGTCCATCGACCCGCGGCCCACGGGTCAAACGACCCTAGTGTTCGCTACGACGTGGTCGTACCTTCGGCAGCAGATCAGCAATAGCACCCCGACTCGAGGAGGATCCCG",
"ACCGTCGATGTGCCCGGTCGCGCCGCGTCCACCTCGGTCATCGACCCCACGATGAGGACGCCATCGGCCGCGACCAAGCCCCGTGAAACTCTGACGGCGTGCTGGCCGGGCTGCGGCACCTGATCACCTTAGGGCACTTGGGCCACCACAACGGGCCGCCGGTCTCGACAGTGGCCACCACCACACAGGTGACTTCCGGCGGGACGTAAGTCCCTAACGCGTCGTTCCGCACGCGGTTAGCTTTGCTGCC",
"GGGTCAGGTATATTTATCGCACACTTGGGCACATGACACACAAGCGCCAGAATCCCGGACCGAACCGAGCACCGTGGGTGGGCAGCCTCCATACAGCGATGACCTGATCGATCATCGGCCAGGGCGCCGGGCTTCCAACCGTGGCCGTCTCAGTACCCAGCCTCATTGACCCTTCGACGCATCCACTGCGCGTAAGTCGGCTCAACCCTTTCAAACCGCTGGATTACCGACCGCAGAAAGGGGGCAGGAC",
"GTAGGTCAAACCGGGTGTACATACCCGCTCAATCGCCCAGCACTTCGGGCAGATCACCGGGTTTCCCCGGTATCACCAATACTGCCACCAAACACAGCAGGCGGGAAGGGGCGAAAGTCCCTTATCCGACAATAAAACTTCGCTTGTTCGACGCCCGGTTCACCCGATATGCACGGCGCCCAGCCATTCGTGACCGACGTCCCCAGCCCCAAGGCCGAACGACCCTAGGAGCCACGAGCAATTCACAGCG",
"CCGCTGGCGACGCTGTTCGCCGGCAGCGTGCGTGACGACTTCGAGCTGCCCGACTACACCTGGTGACCACCGCCGACGGGCACCTCTCCGCCAGGTAGGCACGGTTTGTCGCCGGCAATGTGACCTTTGGGCGCGGTCTTGAGGACCTTCGGCCCCACCCACGAGGCCGCCGCCGGCCGATCGTATGACGTGCAATGTACGCCATAGGGTGCGTGTTACGGCGATTACCTGAAGGCGGCGGTGGTCCGGA",
"GGCCAACTGCACCGCGCTCTTGATGACATCGGTGGTCACCATGGTGTCCGGCATGATCAACCTCCGCTGTTCGATATCACCCCGATCTTTCTGAACGGCGGTTGGCAGACAACAGGGTCAATGGTCCCCAAGTGGATCACCGACGGGCGCGGACAAATGGCCCGCGCTTCGGGGACTTCTGTCCCTAGCCCTGGCCACGATGGGCTGGTCGGATCAAAGGCATCCGTTTCCATCGATTAGGAGGCATCAA",
"GTACATGTCCAGAGCGAGCCTCAGCTTCTGCGCAGCGACGGAAACTGCCACACTCAAAGCCTACTGGGCGCACGTGTGGCAACGAGTCGATCCACACGAAATGCCGCCGTTGGGCCGCGGACTAGCCGAATTTTCCGGGTGGTGACACAGCCCACATTTGGCATGGGACTTTCGGCCCTGTCCGCGTCCGTGTCGGCCAGACAAGCTTTGGGCATTGGCCACAATCGGGCCACAATCGAAAGCCGAGCAG",
"GGCAGCTGTCGGCAACTGTAAGCCATTTCTGGGACTTTGCTGTGAAAAGCTGGGCGATGGTTGTGGACCTGGACGAGCCACCCGTGCGATAGGTGAGATTCATTCTCGCCCTGACGGGTTGCGTCTGTCATCGGTCGATAAGGACTAACGGCCCTCAGGTGGGGACCAACGCCCCTGGGAGATAGCGGTCCCCGCCAGTAACGTACCGCTGAACCGACGGGATGTATCCGCCCCAGCGAAGGAGACGGCG",
"TCAGCACCATGACCGCCTGGCCACCAATCGCCCGTAACAAGCGGGACGTCCGCGACGACGCGTGCGCTAGCGCCGTGGCGGTGACAACGACCAGATATGGTCCGAGCACGCGGGCGAACCTCGTGTTCTGGCCTCGGCCAGTTGTGTAGAGCTCATCGCTGTCATCGAGCGATATCCGACCACTGATCCAAGTCGGGGGCTCTGGGGACCGAAGTCCCCGGGCTCGGAGCTATCGGACCTCACGATCACC"]

t = 10
k = 15
N = 100

Current_Best_Motifs = RandomizedMotifSearch(Dna, k, t)
Best_Motifs = Current_Best_Motifs
for i in range(N-1):
    Current_Best_Motifs = RandomizedMotifSearch(Dna, k, t)
    if Score(Current_Best_Motifs) < Score(Best_Motifs):
        Best_Motifs = Current_Best_Motifs

print(Best_Motifs)

print(Score(Best_Motifs))
