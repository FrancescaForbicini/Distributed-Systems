# Distributed-Systems
My colleague and I followed at Politecnico of Milano the course "Distributed Systems". We made the project called "Transactional key-value store" that consisted in 
implementing a distributed transactional key-value store.
##
  1.Requirements:

      Clients submit transactions. Each transaction is a list of read and write operations:
        
        ● write(k, v) inserts/updates value v for key k
        ● read(k) returns the value associated to key k (or null if the key is not present)

  2.The store is internally partitioned and replicated: assuming N nodes, each key (with its
    values) is replicated in exactly R nodes, with R<=N being a configuration parameter.
    Clients can interact with the store by contacting one or more nodes and submitting their
    transactions, one by one. Nodes internally coordinate to offer the service.
    The store should offer sequential replication consistency and serializable transactional
    isolation. Your design should favour solutions that maximize system performance, in terms
    of query latency and throughput.

  3.We simulated the project using OmNet++. 

  4.Assumptions
  
    We assumed reliable processes and reliable links (using TCP to approximate reliable links
    and assuming no network partitions happens)
