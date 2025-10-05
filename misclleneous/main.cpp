public static List<Integer> getPopularityOrder(List<List<Integer>> song_preferences) {
    int n = song_preferences.size();  // number of users
    int m = song_preferences.get(0).size();  // number of songs

    // Build a preference map for each user
    List<Map<Integer, Integer>> userPref = new ArrayList<>();
    for (int i = 0; i < n; i++) {
        Map<Integer, Integer> map = new HashMap<>();
        for (int j = 0; j < m; j++) {
            map.put(song_preferences.get(i).get(j), j);  // song ID -> rank
        }
        userPref.add(map);
    }

    // Count how many wins each song has in pairwise comparisons
    int[] wins = new int[m];  // wins[i] = number of pairwise wins for song i

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            if (i == j) continue;
            int vote = 0;
            for (int k = 0; k < n; k++) {
                int ind1 = userPref.get(k).get(i);
                int ind2 = userPref.get(k).get(j);
                if (ind1 < ind2) vote++;
            }
            int comp = n / 2 + 1;
            if (vote >= comp || (n % 2 == 0 && vote == n / 2 && i < j)) {
                wins[i]++;
            }
        }
    }

    // Prepare the final list of song indices and sort by number of wins descending
    List<Integer> result = new ArrayList<>();
    for (int i = 0; i < m; i++) result.add(i);

    result.sort((a, b) -> wins[b] - wins[a]);  // descending order of wins

    return result;
}
