import random

def GibbsSampler(Dna, k, t, N):
    Current_Motifs = RandomMotifs(Dna, k, t)
    Best_Motifs = Current_Motifs
    for i in range(N):
        rand_motif_index = random.randint(0, t-1)
        Current_Motifs_without_selected_motif = []
        for i in range(t):
            if not i == rand_motif_index:
                Current_Motifs_without_selected_motif.append(Current_Motifs[i])        
        profile_updated_motifs = ProfileWithPseudocounts(Current_Motifs_without_selected_motif)
        Current_Motifs[rand_motif_index] = ProfileGeneratedString(Dna[rand_motif_index], profile_updated_motifs, k)
        if Score(Current_Motifs) < Score(Best_Motifs):
            Best_Motifs = Current_Motifs
    return Best_Motifs
        
def WeightedDie(Probabilities):
    rand = random.uniform(0, 1)
    current_decimal = 0
    for key in Probabilities.keys():
        current_decimal += Probabilities[key]
        if rand <= current_decimal:
            return key
        
def Normalize(Probabilities):
    Normalized = {}
    sum = 0
    for char in Probabilities.keys():
        sum += Probabilities[char]
    for char in Probabilities.keys():
        Normalized[char] = Probabilities[char] / sum
    return Normalized

def Pr(Text, Profile):
    prob = 1.0
    for i in range(len(Text)):
        prob *= Profile[Text[i]][i]
    return prob

def ProfileGeneratedString(Text, profile, k):
    probabilities = {}
    for i in range(len(Text) - k + 1):
        probabilities[Text[i:i+k]] = Pr(Text[i:i+k], profile)
    normalized_probabilities = Normalize(probabilities)
    return WeightedDie(normalized_probabilities)

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

def RandomMotifs(Dna, k, t):
    random_motifs = []
    for i in range(len(Dna)):
        temp_rand_index = random.randint(0, len(Dna[0])-k)
        random_motifs.append(Dna[i][temp_rand_index:temp_rand_index + k])
    return random_motifs

Dna =["GCGCCCCGCCCGGACAGCCATGCGCTAACCCTGGCTTCGATGGCGCCGGCTCAGTTAGGGCCGGAAGTCCCCAATGTGGCAGACCTTTCGCCCCTGGCGGACGAATGACCCCAGTGGCCGGGACTTCAGGCCCTATCGGAGGGCTCCGGCGCGGTGGTCGGATTTGTCTGTGGAGGTTACACCCCAATCGCAAGGATGCATTATGACCAGCGAGCTGAGCCTGGTCGCCACTGGAAAGGGGAGCAACATC", "CCGATCGGCATCACTATCGGTCCTGCGGCCGCCCATAGCGCTATATCCGGCTGGTGAAATCAATTGACAACCTTCGACTTTGAGGTGGCCTACGGCGAGGACAAGCCAGGCAAGCCAGCTGCCTCAACGCGCGCCAGTACGGGTCCATCGACCCGCGGCCCACGGGTCAAACGACCCTAGTGTTCGCTACGACGTGGTCGTACCTTCGGCAGCAGATCAGCAATAGCACCCCGACTCGAGGAGGATCCCG", "ACCGTCGATGTGCCCGGTCGCGCCGCGTCCACCTCGGTCATCGACCCCACGATGAGGACGCCATCGGCCGCGACCAAGCCCCGTGAAACTCTGACGGCGTGCTGGCCGGGCTGCGGCACCTGATCACCTTAGGGCACTTGGGCCACCACAACGGGCCGCCGGTCTCGACAGTGGCCACCACCACACAGGTGACTTCCGGCGGGACGTAAGTCCCTAACGCGTCGTTCCGCACGCGGTTAGCTTTGCTGCC", "GGGTCAGGTATATTTATCGCACACTTGGGCACATGACACACAAGCGCCAGAATCCCGGACCGAACCGAGCACCGTGGGTGGGCAGCCTCCATACAGCGATGACCTGATCGATCATCGGCCAGGGCGCCGGGCTTCCAACCGTGGCCGTCTCAGTACCCAGCCTCATTGACCCTTCGACGCATCCACTGCGCGTAAGTCGGCTCAACCCTTTCAAACCGCTGGATTACCGACCGCAGAAAGGGGGCAGGAC", "GTAGGTCAAACCGGGTGTACATACCCGCTCAATCGCCCAGCACTTCGGGCAGATCACCGGGTTTCCCCGGTATCACCAATACTGCCACCAAACACAGCAGGCGGGAAGGGGCGAAAGTCCCTTATCCGACAATAAAACTTCGCTTGTTCGACGCCCGGTTCACCCGATATGCACGGCGCCCAGCCATTCGTGACCGACGTCCCCAGCCCCAAGGCCGAACGACCCTAGGAGCCACGAGCAATTCACAGCG", "CCGCTGGCGACGCTGTTCGCCGGCAGCGTGCGTGACGACTTCGAGCTGCCCGACTACACCTGGTGACCACCGCCGACGGGCACCTCTCCGCCAGGTAGGCACGGTTTGTCGCCGGCAATGTGACCTTTGGGCGCGGTCTTGAGGACCTTCGGCCCCACCCACGAGGCCGCCGCCGGCCGATCGTATGACGTGCAATGTACGCCATAGGGTGCGTGTTACGGCGATTACCTGAAGGCGGCGGTGGTCCGGA", "GGCCAACTGCACCGCGCTCTTGATGACATCGGTGGTCACCATGGTGTCCGGCATGATCAACCTCCGCTGTTCGATATCACCCCGATCTTTCTGAACGGCGGTTGGCAGACAACAGGGTCAATGGTCCCCAAGTGGATCACCGACGGGCGCGGACAAATGGCCCGCGCTTCGGGGACTTCTGTCCCTAGCCCTGGCCACGATGGGCTGGTCGGATCAAAGGCATCCGTTTCCATCGATTAGGAGGCATCAA", "GTACATGTCCAGAGCGAGCCTCAGCTTCTGCGCAGCGACGGAAACTGCCACACTCAAAGCCTACTGGGCGCACGTGTGGCAACGAGTCGATCCACACGAAATGCCGCCGTTGGGCCGCGGACTAGCCGAATTTTCCGGGTGGTGACACAGCCCACATTTGGCATGGGACTTTCGGCCCTGTCCGCGTCCGTGTCGGCCAGACAAGCTTTGGGCATTGGCCACAATCGGGCCACAATCGAAAGCCGAGCAG", "GGCAGCTGTCGGCAACTGTAAGCCATTTCTGGGACTTTGCTGTGAAAAGCTGGGCGATGGTTGTGGACCTGGACGAGCCACCCGTGCGATAGGTGAGATTCATTCTCGCCCTGACGGGTTGCGTCTGTCATCGGTCGATAAGGACTAACGGCCCTCAGGTGGGGACCAACGCCCCTGGGAGATAGCGGTCCCCGCCAGTAACGTACCGCTGAACCGACGGGATGTATCCGCCCCAGCGAAGGAGACGGCG", "TCAGCACCATGACCGCCTGGCCACCAATCGCCCGTAACAAGCGGGACGTCCGCGACGACGCGTGCGCTAGCGCCGTGGCGGTGACAACGACCAGATATGGTCCGAGCACGCGGGCGAACCTCGTGTTCTGGCCTCGGCCAGTTGTGTAGAGCTCATCGCTGTCATCGAGCGATATCCGACCACTGATCCAAGTCGGGGGCTCTGGGGACCGAAGTCCCCGGGCTCGGAGCTATCGGACCTCACGATCACC"]

t = 10
k = 15
N = 100

Current_Best_Motifs = GibbsSampler(Dna, k, t, N)
Best_Motifs = Current_Best_Motifs
for i in range(19):
    Current_Best_Motifs = GibbsSampler(Dna, k, t, N)
    if Score(Current_Best_Motifs) < Score(Best_Motifs):
        Best_Motifs = Current_Best_Motifs

print(Best_Motifs)

print(Score(Best_Motifs))
