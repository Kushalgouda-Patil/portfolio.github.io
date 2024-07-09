<!-- # Algorithmic Problem Solving Portfolio -->
## 📘 Course Information

- **Course Name:** Algorithmic Problem Solving
- **Course Code:** 23ECSE309
- **Name:** Kushalgouda Shivanagouda Patil
- **University:** KLE Technological University, Hubballi-31

## 📑 Table of Contents

1. [Introduction](#introduction)
2. [Market Analysis](#market-analysis)
2. [Objectives](#objectives)
2. [System Design](#system-design)
3. [Business Use Cases](#Business-Use-Cases)
4. [References](#References)


## Introduction

Spotify is a digital music, podcast, and video service that gives access to millions of songs and other content from creators all over the world. It is one of the largest music streaming service providers, with over 615 million monthly active users, including 239 million paying subscribers, as of March 2024. Spotify offers digital copyright restricted recorded audio content, including more than 100 million songs and six million podcast titles, from record labels and media companies. As a freemium service, basic features are free with advertisements and limited control, while additional features, such as offline listening and commercial-free listening, are offered via paid subscriptions. Users can search for music based on artist, album, or genre, and can create, edit, and share playlists.

## Market Analysis
Spotify operates on a freemium business model, offering both a free ad-supported tier and a paid subscription without ads. This model has fueled rapid user growth — Spotify has added over 400 million users in just the last 5 years. However, converting those users to paying subscribers has been a greater challenge.

Over the past year, Spotify has focused heavily on improving profitability. In addition to subscription price hikes rolled out globally, Spotify has laid off 6% of its workforce and scaled back spending on podcast content and marketing.

Improving profitability is crucial for Spotify to reassure investors. Since going public in 2018 at a $30 billion valuation, Spotify has yet to deliver consistent profits, leading its stock price to underperform the broader market.

## Objectives
 - Analyse the architecture through system design
 - Identify existing and new business use cases.
 - Propose algorithm and analyse with time and space complexities for use cases

## System Design
### Functional Requirements
   1. As a user, I should be able to search for songs based on the song name/artist name etc.
   1. As a user, I should be able to play the selected song.

### Non-Functional Requirements

   1. Latency: Low latency is vital for immediate music playback after a user's selection, quick search results, and responsive user interface interactions.
   1. Scalability: Scalability ensures that as the number of users increases, the system can handle the additional load without performance degradation
   1. Availability: The users should be able to access music streaming, search functions, and other features without interruptions
   1. Robustness: Robustness includes the ability to deal with invalid user input, network issues, server failures, and unexpected behavior from client applications.

### Capacity Requirements

   1. Assume that there are around 100 millions songs
   1. Assume that the size per file is around 5MB.
   1. Assume that the song metadata size is around 1KB.

This implies that there is a storage requirement of 500 TB to store the song data. Additionally, the storage requirement of the song metadata is around 1 GB.
### High Level Design:
![high level design](https://images.ctfassets.net/dwexedm4848a/1fbUbOQ1YGSi4LNKhypCm3/215df587d28bbf3c14ae46e97ec89f92/Untitled-2023-12-04-1715.png)

### Components:

   - SpotifyWebServer: It acts as a BFF that performs authorization, rate limiting and other validations.
   - SongSearchService: It is used to return the query result for song search by user
   - Elasticsearch: To speed up the search results on song name/artist/lyrics or other metadata, an indexing service like Elasticsearch can be used. This creates an index of all the searchable content, allowing for quick retrieval of search results.
   - SongMetadataService: Service that has APIs for getting data from MetadataDB.
   - MetadataDB: System of record for the Songs Metadata
    SongStreamingService: It is used to get the song audio file for streaming
   - ObjectStore: System of record for the audio filea
   - CDN: Content Delivery Network that caches songs for better Latency

## Business Use Cases
1. **Playlist Management**
   - **Challenge:** Efficiently handle operations on playlist.
   - **Data structure and Algorithm:** Doubly linked list data structure.
   - **Description:** Doubly linked list allows insertion and deletion of songs in constant time. It provides quick access to previous and next songs making a ideal choice for playlist. The lookup time is O(n) which has minimal effect since playlist size will not be that big to count on.
   - Find the sample code [here](https://github.com/Kushalgouda-Patil/spotify.github.io/blob/main/dll.c)
2. **Sorting songs**
   - **Challenge:** Quickly sort the songs based on applied filters
   - **Data structure and Algorithm:** Merge sort
   - **Description:** A divide-and-conquer, stable sorting algorithm that works by recursively creating sub-lists for every element in the list. It can be implemented with constant auxillary space. Due to the nature of the algorithm requiring less random access of it is best suited for linked lists
   - Find the sample code [here](https://github.com/Kushalgouda-Patil/DSA/blob/main/sorting_techniques/merge_sort.c)
3. **Shuffle songs**
   - **Challenge:** Shuffle songs randomly in playlist
   - **Data structure and Algorithm:** Fisher–Yates shuffle
   - **Description:** The Fisher–Yates shuffle is an algorithm for shuffling a finite sequence. The algorithm takes a list of all the elements of the sequence, and continually determines the next element in the shuffled sequence by randomly drawing an element from the list until no elements remain. The algorithm produces an unbiased permutation: every permutation is equally likely.
   - Find the sample code [here](https://github.com/JDSherbert/Fisher-Yates-Shuffle/blob/main/C/Shuffle.c)
4. **Search songs**
   - **Challenge:** Quickly search song 
   - **Data structure and Algorithm:** Soundex algorithm
   - **Description:** The names of song may have different language origins and user shall not search the exact string. Soundex algorithm considers phonetics of a string to search similar phonetic string which is very useful to search required song.
   - Find the sample code [here](https://github.com/Gregory-crypto/solid-pluses/blob/main/soundex.cpp)
5. **User Segmentation**
   - **Challenge:** To group users into clusters for targeted advertising and recommendations
   - **Data structure and Algorithm:** K-means clustering algorithm
   - **Description:** Groups users into segments based on behavior and preferences for targeted marketing and content recommendations.
   - Find the sample code [here](https://github.com/srafay/Machine_Learning_A-Z/blob/master/Part%204%20-%20Clustering/Section%2024%20-%20K-Means%20Clustering/kmeans.py)
6. **Search Autocomplete**
   - **Challenge:** To give right suggestions to autocomplete
   - **Data structure and Algorithm:** Trie data structure
   - **Description:** Optimized for storing large datasets of strings with shared prefixes. Search time is (n), where n is the length of the prefix, making them very efficient for autocomplete.
7. **Content Caching**
   - **Challenge:** To cache the content for faster access
   - **Data structure and Algorithm:** LRU Cache eviction policy
   - **Description:** Stores frequently accessed content closer to users for faster retrieval and reduced server load.
   - Find the sample code [here](https://github.com/SUMUKHA-PK/LRU-Cache/blob/master/C/lru.c)
8. **Ad selection and insertion**
   - **Challenge:** To show relevent advertisements in between songs to generate profit.
   - **Data structure and Algorithm:** Content-Based Filtering
   - **Description:** Content based filtering uses dot product to suggest relevent ads. This algorithm may not work if user has less interests and may stuck in a loop.
   - Find the sample code [here]()
9. **Social features**
   - **Challenge:** To connect with friends and share the songs and playlists
   - **Data structure and Algorithm:** Breadth First search with graphs.
   - **Description:** Graph is used to represent the connection between users. BFS is used to recommend similar songs.
   - Find the sample code [here](https://github.com/Kushalgouda-Patil/DSA/blob/main/graphs/bfsndfs.c)
10. **Collaborative playlist**
    - **Challenge:** Users can have shared playlist with permissions to modify.
    - **Data structure and Algorithm:** Concurrent doubly linked list with publish/subscribe model 
    - **Description:** Concurrent doubly linked list allows multiple users to modify the data structure. Pub/sub model allows real time data synchronization.
    - Find the sample code [here]()

## Efficiency analysis

|---------------------------------------|------------------------------------------------|-----------------------------------------------|
| **Algorithm**                         | **Time Complexity**                            | **Space Complexity**                          |
|---------------------------------------|------------------------------------------------|-----------------------------------------------|
| **Trie Data Structure**               | Insert/Search: O(n)                            | O(n) each node                                |
| **BFS and DFS**                       | O(V + E)                                       | O(V)                                          |
| **Merge Sort**                        | Worst/Avg: O(nlog n)                           | O(n)                                          |
| **Least Recently Used (LRU) Cache**   | O(1) for both get and put operations           | O(capacity)                                   |
| **K-means Clustering**                | O(n * k * I * d)<br>where:<br>n = number of data points<br>k = number of clusters<br>I = number of iterations<br>d = dimensionality of data                                                 | O(n * k)                                      |
| **Heap Data Structure**               | Insert/Delete/Extract: O(log n)                | O(n)                                          |
|---------------------------------------|------------------------------------------------|-----------------------------------------------|

## References
1.  [The Soundex Indexing System"](https://www.archives.gov/research/census/soundex.html). National Archives. 
2. [What is spotify](https://support.spotify.com/in-en/article/what-is-spotify/)
3. [Spotify Wikipedia](https://en.wikipedia.org/wiki/Spotify)
4. [Code Mentor](https://www.codementor.io/@mattgoldspink/computer-algorithms-explained-learning-through-spotify-du10866vw)
5. https://engineering.atspotify.com/2014/02/how-to-shuffle-songs/
6. https://www.baeldung.com/cs/efficiently-sorting-linked-lists
7. https://developers.google.com/machine-learning/recommendation/content-based/basics










