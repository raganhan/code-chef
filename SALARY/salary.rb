#!/usr/bin/env ruby

class Equalizer
	def initialize(nworkers, salaries)		
		raise 'Error: number of workers is different from number of salaries' unless nworkers == salaries.length	
		@salaries = salaries
	end

	def minimum_operations
		number_of_iterations = 0
		while (@salaries.count(@salaries[0]) != @salaries.length) do 
			max_index = @salaries.index(@salaries.max)
			@salaries.each_with_index do |salary, index|
				@salaries[index] += 1 unless max_index == index
			end		
			number_of_iterations += 1
		end

		number_of_iterations
	end
end

class Reader
	def initialize(file)
		@file = file
	end

	def read()
		equalizers = []

		lines = @file.readlines 
		size = lines[0].to_i

		lines[1..lines.length].each_slice(2) do |slice|
			nworkers = slice[0].chomp.to_i
			salaries = slice[1].chomp.split(' ').map { |x| x.to_i }
			equalizers << Equalizer.new(nworkers, salaries)
		end

		equalizers	
	end
end

equalizers = Reader.new(ARGF).read()

equalizers.each do |eq|
	puts eq.minimum_operations
end
